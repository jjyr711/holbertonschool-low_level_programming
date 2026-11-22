#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

/**
 * next_value - generates next pseudo-random unsigned int
 * @state: pointer to PRNG state
 *
 * Return: updated state
 */
static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

/**
 * build_dataset - populates static dataset array with deterministic values
 */
static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

/**
 * process_dataset - transforms each element in dataset
 */
static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

/**
 * reduce_checksum - computes rolling checksum over dataset
 *
 * Return: computed checksum
 */
static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

/**
 * main - benchmarks build, process, and reduce phases
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long checksum;
	clock_t t_start;
	clock_t t_build;
	clock_t t_process;
	clock_t t_end;
	double total_sec;
	double build_sec;
	double process_sec;
	double reduce_sec;

	t_start = clock();
	build_dataset();
	t_build = clock();
	process_dataset();
	t_process = clock();
	checksum = reduce_checksum();
	t_end = clock();

	if (checksum == 0ul)
		printf("impossible\n");

	total_sec = (double)(t_end - t_start) / (double)CLOCKS_PER_SEC;
	build_sec = (double)(t_build - t_start) / (double)CLOCKS_PER_SEC;
	process_sec = (double)(t_process - t_build) / (double)CLOCKS_PER_SEC;
	reduce_sec = (double)(t_end - t_process) / (double)CLOCKS_PER_SEC;

	printf("TOTAL seconds: %.6f\n", total_sec);
	printf("BUILD_DATA seconds: %.6f\n", build_sec);
	printf("PROCESS seconds: %.6f\n", process_sec);
	printf("REDUCE seconds: %.6f\n", reduce_sec);

	return (0);
}
