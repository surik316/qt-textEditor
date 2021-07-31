# Разработать графическое приложение с использованием библиотеки Qt – текстовый редактор:
* с подсветкой текущей строки;
* с нумерацией строк;
* с подсветкой синтаксиса (переключение): Си89, Си++98/03
Заголовок окна должен содержать имя редактируемого файла (ограниченное 32 символами + троеточие) и признак того что файл был изменен (звездочка в начале имени + курсив) с момента последнего сохранения.
Окно содержит главное меню (и наследуется от QMainWindow) состоящее из пунктов:
### Файл [кнопки]
* Новый
* Открыть
* Сохранить
* Сохранитькак e) Выход
### Правка [кнопки] 
* Отменить
* Повторить 
* Копировать
* Вырезать
* Вставить
* Найти
* Найти и заменить 
* Выделитьвсе
### Формат
* Перенос по словам [галочка]
* Выбор шрифта - открывается модальный диалог выбора шрифта
### Вид [галочки, где не указано иное]
* Выбор цвета фона [кнопка] - открывает модальное окно выбора цвета
* Выбор цвета текущей строки [кнопка] - открывает модальное окно выборац вета
* Вкл/Выкл отображения нумерации строк
* Вкл/Выкл отображения панели инструментов
* Вкл/Выкл отображения строки состояния
* Вкл/Выкл подсветки синтаксиса
* Выбор синтаксиса (для подсветки) [дочернее меню] - доступно всегда, один
синтаксис в дочернем меню выбран всегда
* Выбор/Редактирование стиля подсветки [дочернее меню] - для текущего
синтаксиса, по умолчанию выбран Default
* Изменить [кнопка] - измененный стиль сохраняется в файл, имя файла
становится именем стиля, стиль становится активным
* Загрузка стиля из файла [кнопка] - имя файла становится именем стиля,
стиль становится активным
* Обязательная кнопка Default
* доступные стили [перечисляются все стили которые были обнаружены]
### Справка
a) О программе - открывает модальное окно содержащее фото и имя автора, дату
сборки, версию Qt с которой собиралось, версию Qt с которой запущено, кнопку закрывающую окно
Ниже главного меню располагается панель инструментов (отображение которой контролируется в меню Вид) с кнопками (с картинками, текстовое описание во всплывающей подсказке):
1) Новыйдокумент
2) Открыть
3) Сохранить
4) Отменить
5) Повторить
6) Копировать
7) Вырезать
8) Вставить
### Найти / Найти и заменить (как выпадающая кнопка) - открывающая (немодальное) диалоговое окно
В центральной части окна располагается область для редактирования текста. При нажатии левой кнопки курсор вставляется в позицию. При двойном нажатии левой кнопки выделяется слово под курсором. При нажатии правой кнопки (далее - если нет=*, есть=** выделения) курсор вставляется в позицию и выдается контекстное меню (кнопки могут быть неактивны): отменить, повторить, выделить*, выделить строку*, копировать**, вырезать**, вставить (** или если есть текст в буфере обмена), удалить**, выделить все.
Нижнюю часть окна занимает строка состояния. Информация разделена на три столбца: текущая позиция курсора (строка:столбец); время (и дата если другие сутки) последней операции (сохранения/изменения); количество строк, слов, символов, размер в килобайтах.
Дополнительный балл – подсветка синтаксиса Си++11/14 (Си++17, Си++20)
Дополнительный балл – сохранение настроек приложения в ini-файл.
