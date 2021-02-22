# Abipusis dėklas _deque_

> VU ISI Duomenų struktūros ir algoritmai, užduotis A13.

Duomenų struktūra _abipusis dėklas_ – tai duomenų masyvas, kuriam apibrėžtos tokios operacijos:

- elemento įterpimas į abipusio dėklo pradžią [pushFront](#pushfront)
- elemento įterpimas į abipusio dėklo pabaigą [pushBack](#pushback)
- elemento pašalinimas iš abipusio dėklo pradžios [popFront](#popfront)
- elemento pašalinimas iš abipusio dėklo pabaigos [popBack](#popback)
- abipusio dėklo pradžios skaitymas [getFront](#getfront)
- abipusio dėklo pabaigos skaitymas [getBack](#getback)
- abipusio dėklo panaikinimas [clear](#clear)

Žemiau pateikiami visi metodai, kurie buvo implementuoti kuriant abipusio dėklo klasę:

- [clear](#clear)
- [getAt](#getat)
- [getBack](#getback)
- [getFront](#getfront)
- [getSize](#getsize)
- [isEmpty](#isempty)
- [popAt](#popat)
- [popBack](#popback)
- [popFront](#popfront)
- [print](#print)
- [printReverse](#printreverse)
- [pushAt](#pushat)
- [pushBack](#pushback)
- [pushFront](#pushfront)

## clear

`void clear();`

📚 Pašalina visus elementus iš deque'o (kurie yra sunaikinami), paliekant 0 dydžio konteinerį.

🛠️ **Parametrai**: none

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "Deque size: " << deque.getSize() << std::endl;
  deque.clear();
  std::cout << "Deque size: " << deque.getSize() << std::endl;

  return 0;

  // Deque size: 10
  // Deque size: 0
}
```

---

## getAt

`<typename T> getAt(int index);`

📚 Grąžina reikšmę, saugomą _i-tojo_ elemento `value` atribute.

Kai `index` reikšmė yra `0`, tai grąžina pirmojo elemento reikšmę, kaip ir [getFront()](#getfront). Jei `index` reikšmė yra `size-1`, tai grąžina paskutinio elemento reikšmę, kaip ir [getBack()](#getback).

🛠️ **Parametrai**: `int index` - elemento indeksas, skaičiuojant nuo `0`.

⬅️ **Return value**: `<typename T>`

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "getAt(1): " << deque.getAt(1) << std::endl;
  std::cout << "getAt(5): " << deque.getAt(5) << std::endl;
  std::cout << "getAt(-1): " << deque.getAt(-1) << std::endl;
  std::cout << "getAt(-2): " << deque.getAt(-2) << std::endl;

  return 0;

  // getAt(1): 1
  // getAt(5): 5
  // getAt(-1): 9
  // getAt(-2): 8
}
```

---

## getBack

`<typename T> getBack();`

📚 Grąžina reikšmę, saugomą paskutinio elemento `value` atribute.

🛠️ **Parametrai**: none

⬅️ **Return value**: `<typename T>`

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "getBack(): " << deque.getBack() << std::endl;

  return 0;

  // getBack(): 9
}
```

---

## getFront

`<typename T> getFront();`

📚 Grąžina reikšmę, saugomą pirmojo elemento `value` atribute.

🛠️ **Parametrai**: none

⬅️ **Return value**: `<typename T>`

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "getFront(): " << deque.getFront() << std::endl;

  return 0;

  // getFront(): 0
}
```

---

## getSize

`int getSize();`

📚 Grąžina kontainerio elementų kiekį. Jei konteineris yra tuščias, tai grąžina `0`.

🛠️ **Parametrai**: none

⬅️ **Return value**: `int`

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "getSize(): " << deque.getSize() << std::endl;
  deque.popBack();
  deque.popFront();
  std::cout << "getSize(): " << deque.getSize() << std::endl;

  return 0;

  // getSize(): 10
  // getSize(): 8
}
```

---

## isEmpty

`bool isEmpty();`

📚 Grąžina `bool` reikšmę, žyminčią, ar konteineris yra tuščias.

🛠️ **Parametrai**: none

⬅️ **Return value**: `bool`

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "isEmpty(): " << std::boolalpha << deque.isEmpty() << std::endl;
  deque.clear();
  std::cout << "isEmpty(): " << std::boolalpha << deque.isEmpty() << std::endl;

  return 0;

  // isEmpty(): false
  // isEmpty(): true
}
```

---

## popAt

`void popAt(int index);`

📚 Pašalina _i-tąjį_ konteinerio elementą ir sumažina konteinerio dydį. Pašalintas elementas yra sunaikinamas.

Kai `index` reikšmė yra `0`, tai pašalina pirmąjį elementą, kaip ir [popFront()](#popfront). Jei `index` reikšmė yra `size-1`, tai pašalina paskutinįjį elementą, kaip ir [popBack()](#popback).

🛠️ **Parametrai**: `int index` - elemento indeksas, skaičiuojant nuo `0`.

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "Deque before: ";
  deque.print();

  deque.popAt(1);
  deque.popAt(4);
  deque.popAt(-1);

  std::cout << "Deque after: ";
  deque.print();

  return 0;

  // Deque before: 0 1 2 3 4 5 6 7 8 9
  // Deque after:  0 2 3 4 6 7 8
}
```

---

## popBack

`void popBack();`

📚 Pašalina paskutinįjį konteinerio elementą ir sumažina konteinerio dydį. Pašalintas elementas yra sunaikinamas.

🛠️ **Parametrai**: none

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "Deque before: ";
  deque.print();

  deque.popBack();
  deque.popBack();
  deque.popBack();

  std::cout << "Deque after: ";
  deque.print();

  return 0;

  // Deque before: 0 1 2 3 4 5 6 7 8 9
  // Deque after:  0 1 2 3 4 5 6
}
```

---

## popFront

`void popFront();`

📚 Pašalina pirmąjį konteinerio elementą ir sumažina konteinerio dydį. Pašalintas elementas yra sunaikinamas.

🛠️ **Parametrai**: none

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "Deque before: ";
  deque.print();

  deque.popFront();
  deque.popFront();
  deque.popFront();

  std::cout << "Deque after: ";
  deque.print();

  return 0;

  // Deque before: 0 1 2 3 4 5 6 7 8 9
  // Deque after:  3 4 5 6 7 8 9
}
```

---

## print

`void print();`

📚 Į komandinę eilutę atspausdina visų konteinerio elementų `value` reikšmes iš kairės į dešinę.

🛠️ **Parametrai**: none

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "print(): ";
  deque.print();

  return 0;

  // print(): 0 1 2 3 4 5 6 7 8 9
}
```

---

## printReverse

`void printReverse();`

📚 Į komandinę eilutę atspausdina visų konteinerio elementų `value` reikšmes iš dešinės į kairę.

🛠️ **Parametrai**: todo

⬅️ **Return value**: todo

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "printReverse(): ";
  deque.printReverse();

  return 0;

  // printReverse(): 9 8 7 6 5 4 3 2 1 0
}
```

---

## pushAt

`void pushAt(int index, type_value value);`

📚 Sukuria naują elementą ir jam priskiria reišmę `value`. Padidina konteinerio dydį ir naują elementą išsaugo konteinerio _i-tajame_ indekse. Elementai, kurie yra _dešiniau_ nuo indekso, per vieną poziciją yra perstumiami į dešinę.

Kai `index` reikšmė yra `0`, tai naująjį elementą įkelia į konteinerio pradžią, kaip ir [pushFront()](#pushFront). Jei `index` reikšmė yra `size-1`, tai naująjį elementą įkelia į konteinerio pabaigą, kaip ir [pushBack()](#pushback).

🛠️ **Parametrai**:

- `int index` - elemento indeksas, skaičiuojant nuo `0`.
- `type_value value` - reikšmė, kuri turi būti priskirta naujai sukurtam elementui.

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "Deque before: ";
  deque.print();

  deque.pushAt(1, 11);
  deque.pushAt(5, 55);
  deque.pushAt(-2, 22);

  std::cout << "Deque after: ";
  deque.print();

  return 0;

  // Deque before: 0 1 2 3 4 5 6 7 8 9
  // Deque after:  0 11 1 2 3 55 4 5 6 7 8 22 9
}
```

---

## pushBack

`void pushBack(type_value value);`

📚 Sukuria naują elementą ir jam priskiria reišmę `value`. Padidina konteinerio dydį ir naują elementą išsaugo konteinerio pabaigoje.

🛠️ **Parametrai**: `type_value value` - reikšmė, kuri turi būti priskirta naujai sukurtam elementui.

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "Deque before: ";
  deque.print();

  deque.pushBack(10);
  deque.pushBack(11);
  deque.pushBack(12);

  std::cout << "Deque after: ";
  deque.print();

  return 0;

  // Deque before: 0 1 2 3 4 5 6 7 8 9
  // Deque after:  0 1 2 3 4 5 6 7 8 9 10 11 12
}
```

---

## pushFront

`void pushFront(type_value value);`

📚 Sukuria naują elementą ir jam priskiria reišmę `value`. Padidina konteinerio dydį ir naują elementą išsaugo konteinerio pradžioje.

🛠️ **Parametrai**: `type_value value` - reikšmė, kuri turi būti priskirta naujai sukurtam elementui.

⬅️ **Return value**: none

```cpp
#include <iostream>
#include "Deque.hpp"

int main() {
  Deque<int> deque;

  for (int i = 0; i < 10; i++) {
    deque.pushBack(i);
  }

  std::cout << "Deque before: ";
  deque.print();

  deque.pushFront(-1);
  deque.pushFront(-2);
  deque.pushFront(-3);

  std::cout << "Deque after: ";
  deque.print();

  return 0;

  // Deque before: 0 1 2 3 4 5 6 7 8 9
  // Deque after: -3 -2 -1 0 1 2 3 4 5 6 7 8 9
}
```
