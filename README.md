# grp
I got tired of coming up with passwords so I made this in minutes 😎

## Features

- Generates random passwords with customizable options.
- Supports options for including uppercase letters, lowercase letters, numbers, and symbols.
- Command-line interface for easy and fast use.

## Building and Installation

1. Clone the repository:

        git clone https://github.com/0xWerz/grp.git

2. Change into the directory:

        cd grp

3. Build the program:

        make    

4. Install the program:

        sudo make install 

## Usage
    
    Usage: pwd_generator [options]
    Options:
    -l <length>    Length of the password (default: 8)
    -e <options>   Character sets to include in the password (default: ulns)
                    u - uppercase characters
                    l - lowercase characters
                    n - numbers
                    s - symbols
    -h             Display this help message

## Examples
    grp -l 12 -e uln
    grp -l 16 -e ulns
    grp -l 20 -e u

## TODO

- [ ] generate multiple passwords at once.
- [ ] save and encrypt passwords to a file with a master password.
- [ ] generate passwords with a master password.
- [ ] share and sync passwords across devices.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.