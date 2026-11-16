ls -la
[200~git clone https://github.com/jjyr711/holbertonschool-low_level_programming.git~
cd holbertonschool-low_level_programming
mkdir -p hello_world
cd hello_world
vi 0-preprocessor
git clone https://github.com/jjyr711/holbertonschool-low_level_programming.git && cd holbertonschool-low_level_programming && mkdir -p hello_world && cd hello_world && printf '#!/bin/bash\ngcc -E $CFILE -o c\n' > 0-preprocessor && chmod u+x 0-preprocessor
mkdir -p hello_world && cd hello_world && printf '#!/bin/bash\ngcc -E $CFILE -o c\n' > 0-preprocessor && chmod u+x 0-preprocessor && cd .. && git init && git add . && git commit -m "First commit - Task 0" && git branch -M main && git remote add origin https://github.com/jjyr711/holbertonschool-low_level_programming.git && git push -u origin main
git config --global user.email "jjyr711@gmail.com"
git config --global user.name "jjyr711"
git remote set-url origin https://github.com/jjyr711/holbertonschool-low_level_programming.git && git add . && git commit -m "Task 0 completed" && git push -u origin main
git remote add origin https://github.com/jjyr711/holbertonschool-low_level_programming.git && git push -u origin main
