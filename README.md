# Get_next_line
Get_next_line — это функция, которая считывает целую строку из файла, индексированного файловым дескриптором fd. 
Затем он выделяет строку с содержимым этой строки без разрыва строки '\n', указывает строку на нее и позволяет вам прочитать строку, заканчивающуюся символом новой строки, из файлового дескриптора.  
Мы будем постепенно читать файл с помощью read(), который автоматически перемещает свою позицию в файловом дескрипторе. 
Когда мы снова вызываем функцию для того же файла, она захватывает следующую строку и выписывает на экран. 
Этот проект посвящен распределению памяти и тому, когда освобождать и выделять память для предотвращения утечек.
## Запуск функции
```
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c && ./a.out
```
