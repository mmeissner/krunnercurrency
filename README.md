# krunnercurrency
A currency converter plugin for KRunner.

It works using [Free Currency Rates API](https://github.com/fawazahmed0/currency-api)

## Usage
There are two recognized formats:
1. `exchange <amount> <currency> to <currency>`
2. `<amount> <currency> to <currency>`

where `<currency>` is a valid [currency code](https://www.iban.com/currency-codes).

## Dependencies

Requires Qt6/KF6 (Plasma 6).

Arch/Manjaro:

```bash
sudo pacman -S cmake extra-cmake-modules krunner
```

Ubuntu/Debian:

```bash
sudo apt install cmake extra-cmake-modules build-essential qt6-base-dev libkf6runner-dev libkf6i18n-dev gettext
```

## Installation
1. Install dependencies
2. Clone this repository
3. Run install.sh

## Credits/Thanks
- [santiacq/krunnercrypto](https://github.com/santiacq/krunnercrypto) this project was really useful as a reference.
- [alex1701c/EmojiRunner](https://github.com/alex1701c/EmojiRunner) this project was really useful as a reference.
- [jacksonlopes/krunnerStocksMarket](https://github.com/jacksonlopes/krunnerStocksMarket) this project was really useful as a reference.
- [naraesk/krunner-translator](https://github.com/naraesk/krunner-translator) this project was really useful as a reference.
