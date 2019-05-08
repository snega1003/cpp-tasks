## Задания

Создайте класс, который представляет собой поток. Класс должен работать аналогично **std::thread**, 
но без возможности передавать аргументы вызываемой внутрипотока функции.    
Для реализации воспользуйтесь следующими системными вызовами:    
   + [clone(2)](http://man7.org/linux/man-pages/man2/clone.2.html)
   + [waitpid(2)](http://man7.org/linux/man-pages/man2/waitpid.2.html)
   + [kill(2)](http://man7.org/linux/man-pages/man2/kill.2.html)   
   
В классе должны работать, по крайней мере, следующие методы:   
   + конструктор,
   + деструктор,
   + оператор присваивания с перемещением,
   + метод join,
   + метод joinable,
   + метод get_id,
   + метод swap.  
   
Страницы руководства на русском (более старые): [clone(2)](https://www.opennet.ru/man.shtml?topic=clone&russian=0&category=2), 
[waitpid(2)](https://www.opennet.ru/man.shtml?topic=waitpid&russian=0&category=2), 
[kill(2)](https://www.opennet.ru/man.shtml?topic=kill&russian=0&category=2).   
Для принудительного завершения потока используйте сигнал **SIGTERM**. Список
всех сигналов есть в руководстве [signal(7)](http://man7.org/linux/man-pages/man7/signal.7.html).
