# Techniki Programowania - Projekt 3
Projekt polega na wczytaniu, przetworzeniu oraz zwizualizowaniu sygnałów występujących w systemach robotycznych. Projekt będzie realizowany z wykorzystaniem programu CMake.


# Korzystanie z szablonu
## Pobranie projektu
W celu pobrania zależności (biblioteki Eigen oraz Matplot++), nalezy zaciągnąć repozytorium wraz z submodułami korzystając z flagi `--recursive`

`git clone https://github.com/marekjg/tp_projekt_3 --recursive`

## Budowanie projektu
Korzystając z Visual Code i dodatku CMake tools, można buować i uruchamiać program z dolnego paska. Można też z linii poleceń:

```bash
mkdir build
cd build
cmake ..
make -j4
```

## Uruchomienie aplikacji
Tak jak budowanie, można wykorzystać CMake tools w Visual Studio Code albo znaleźć plik wykonywalny (pod nazwą z `add_executable` w pliku `CMakeLists.txt`).

# Zadanie projektowe
