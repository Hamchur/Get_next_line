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
## Проверка на роботоспособность
![alt-текст](https://camo.githubusercontent.com/b199939154038b6e6762dc1bea22e93065cba10bd6b20220f094a6371035697e/68747470733a2f2f692e696d6775722e636f6d2f75344c6936414d2e706e67)
