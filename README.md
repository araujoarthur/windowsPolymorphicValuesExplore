Badly written CPP code that I wrote to explore windows `MAKEPOINTS`, `LOWORD` and `HIWORD` macros and some of the types.

# **x64**
```bash
Mask Used: 0000000000000000000000000000000000000000000000001111111111111111 of size @sizeof DWORD_PTR: 8 sizeof DWORD: 4
 STEPS OF HIWORD                HEX     DEC                 BIN
CAST L TO A DWORD_PTR:        f0f1f2f3 4042388211  0000000000000000000000000000000011110000111100011111001011110011
SHIFT RIGHT L BY 16:          f0f1         61681   0000000000000000000000000000000000000000000000001111000011110001
PERFORMS BITWISE & 0xffff:    f0f1         61681   0000000000000000000000000000000000000000000000001111000011110001
CASTS IT ALL TO A WORD:       f0f1         61681   0000000000000000000000000000000000000000000000001111000011110001



 STEPS OF LOWORD                HEX     DEC                 BIN
CAST L TO A DWORD_PTR:        f0f1f2f3 4042388211  0000000000000000000000000000000011110000111100011111001011110011
PERFORMS BITWISE & 0xffff:    f2f3         62195   0000000000000000000000000000000000000000000000001111001011110011
CASTS IT ALL TO A WORD:       f2f3         62195   0000000000000000000000000000000000000000000000001111001011110011






 STEPS OF MAKEPOINTS
L IS                                   4042388211 | f0f1f2f3 | 0000000000000000000000000000000011110000111100011111001011110011
GETS THE ADDRESS OF L:                  000000A135CFF834 000000A135CFF834  ...
  INTEGER:                                 ADDRESS:     a135cff834
  INTEGER:                                 MID ADDRESS: a135cff836(2)
  INTEGER:                                 END ADDRESS: a135cff838(4)
CASTS IT TO A POINTER TO POINTS:        000000A135CFF834 000000A135CFF834  ...
  STRUCT:                                  Value X:-3341 Value Y:-3855
  STRUCT:                                  Address X:000000A135CFF834 Address Y:000000A135CFF836
DEREF THE POINTER:                      000000A135CFF834 000000A135CFF834  ...
  STRUCT:                                  Value X:-3341 Value Y:-3855
  STRUCT:                                  Bin X:1111111111111111111111111111111111111111111111111111001011110011
                                           Bin Y:1111111111111111111111111111111111111111111111111111000011110001
  STRUCT:                                  Address X:000000A135CFF834 Address Y:000000A135CFF836


 Original Bin:       0000000000000000000000000000000011110000111100011111001011110011
 Bin X:              1111111111111111111111111111111111111111111111111111001011110011

 Bin Y:              1111111111111111111111111111111111111111111111111111000011110001
 Original Bin >> 16: 0000000000000000000000000000000000000000000000001111000011110001


 Original Hex:       f0f1f2f3
 Hex X:              f2f3

 Hex Y:              f0f1
 Original Hex >> 16: f0f1
```
## Data
```bash
 COLS				   0    1    2    3    4    5    6    7      8    9   10   11   12   13   14   15
 Original Bin:       0000 0000 0000 0000 0000 0000 0000 0000 | 1111 0000 1111 0001 1111 0010 1111 0011
 Bin X:              1111 1111 1111 1111 1111 1111 1111 1111 | 1111 1111 1111 1111 1111 0010 1111 0011

 Bin Y:              1111 1111 1111 1111 1111 1111 1111 1111 | 1111 1111 1111 1111 1111 0000 1111 0001
 Original Bin >> 16: 0000 0000 0000 0000 0000 0000 0000 0000 | 0000 0000 0000 0000 1111 0000 1111 0001
 
 Original Hex:       f0f1f2f3
 Hex X:              f2f3

 Hex Y:              f0f1
 Original Hex >> 16: f0f1
```


# **x86**

```bash
Mask Used: 00000000000000001111111111111111 of size  sizeof DWORD_PTR: 4 sizeof DWORD: 4

 STEPS OF HIWORD                HEX     DEC                 BIN
CAST L TO A DWORD_PTR:        f0f1f2f3 4042388211  11110000111100011111001011110011
SHIFT RIGHT L BY 16:          f0f1         61681   00000000000000001111000011110001
PERFORMS BITWISE & 0xffff:    f0f1         61681   00000000000000001111000011110001
CASTS IT ALL TO A WORD:       f0f1         61681   00000000000000001111000011110001



 STEPS OF LOWORD                HEX     DEC                 BIN
CAST L TO A DWORD_PTR:        f0f1f2f3 4042388211  11110000111100011111001011110011
PERFORMS BITWISE & 0xffff:    f2f3         62195   00000000000000001111001011110011
CASTS IT ALL TO A WORD:       f2f3         62195   00000000000000001111001011110011






 STEPS OF MAKEPOINTS
L IS                                   4042388211 | f0f1f2f3 | 11110000111100011111001011110011
GETS THE ADDRESS OF L:                  012FF6EC 012FF6EC  ...
  INTEGER:                                 ADDRESS:     12ff6ec
  INTEGER:                                 MID ADDRESS: 12ff6ee(2)
  INTEGER:                                 END ADDRESS: 12ff6f0(4)
CASTS IT TO A POINTER TO POINTS:        012FF6EC 012FF6EC  ...
  STRUCT:                                  Value X:-3341 Value Y:-3855
  STRUCT:                                  Address X:012FF6EC Address Y:012FF6EE
DEREF THE POINTER:                      012FF6EC 012FF6EC  ...
  STRUCT:                                  Value X:-3341 Value Y:-3855
  STRUCT:                                  Bin X:11111111111111111111001011110011
                                           Bin Y:11111111111111111111000011110001
  STRUCT:                                  Address X:012FF6EC Address Y:012FF6EE


Original Bin:       11110000111100011111001011110011
Bin X:              11111111111111111111001011110011

Bin Y:              11111111111111111111000011110001
Original Bin >> 16: 00000000000000001111000011110001


Original Hex:       f0f1f2f3
Hex X:              f2f3

Hex Y:              f0f1
Original Hex >> 16: f0f1
```
## Data

```bash
COLS0                 1    2    3    4     5    6    7    8
Original Bin:       1111 0000 1111 0001 | 1111 0010 1111 0011
Bin X:              1111 1111 1111 1111 | 1111 0010 1111 0011

Bin Y:              1111 1111 1111 1111 | 1111 0000 1111 0001
Original Bin >> 16: 0000 0000 0000 0000 | 1111 0000 1111 0001

Original Hex:       f0f1f2f3
Hex X:              f2f3

Hex Y:              f0f1
Original Hex >> 16: f0f1
```
