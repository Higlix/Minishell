
# Libft

A small C library with basic functions


## Installation

Install Libft via cloning it to your project folder

```bash
  git clone https://github.com/Higlix/Libft
```
    
## Usage/Examples

```javascript
#include "libft.h"
#include "libft_printer.h"

int main(void)
{
    ft_print("Hello World!");
    ft_putchar_fd('\n', 1);
    return (0);
}

```
#
```bash
make -C libft
gcc myfile.c libft/libft.a -I libft/inc
```
