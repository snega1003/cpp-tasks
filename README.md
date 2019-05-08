# C++ Tasks

Задания для курса по C++.   

Сборка проектов выполнялась с помощью систем сборки **meson** и **ninja** на Linux.    
Тесты - с помощью библиотеки Google test.   
Описания каждого задания внутри папок.   

### Структура проектов:
```
doc                  # документация   
src    
├── test             # код модульных тестов   
│   ├── сomponent1   # структура папок такая же,   
│   ├── component2   # как и в основном коде   
│   └── component3   
└── myproject        # основной код   
├── component1   
├── component2   
└── component3    
```
---

1. Сборка проекта, находясь в папке src:   
```
meson . build   
cd build   
ninja   
meson test   
```

2. Сборка проекта с проверкой корректности работы с памятью:
```
meson configure -Db_sanitize=address   
ninja    
meson test   
```

3. Вычислить покрытие кода тестами:
```
// отмена предыдущей проверки   
meson configure -Db_sanitize=none -Dcpp_args=''   
ninja coverage-text   
```
Полный список возможных команд ninja выводится командой ```ninja -t targets```.

4. Сборка проекта со статическим анализом кода:
```ninja scan-build```

