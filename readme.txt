Программа на C для Linux, которая обходит рекурсивно все
каталоги и файлы, начиная с текущего каталога, и устанавливает права
доступа 0755 на каталоги и 0644 на файлы.

Тесты для проверки написаны с использованием ceedling.
Для установки "install ceedling".
Для запуска теста необходимо в директории test вызвыть команду
"ceedling test:chmod.c" и ввести путь к папке, файлы которой надо проверить.
