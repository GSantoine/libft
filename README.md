# libft - a library of personnal implementations of some libc functions

## 1st project of my 42 cursus

| Project Name | Libft |
| :-: | :-: |
| Description | My personal library of custom implementations of some libc functions |
| Technos | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |

## Usage
#### Build the library
```
git clone https://github.com/GSantoine/libft.git
cd libft
make
```
#### Use the library
Since this a library, you can link it inside the Makefile of your project like so :
```
$(CC) $(CFLAGS) -Llibft -lft -c $< -o $@
```
