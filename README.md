# date-lib

C++ library for Gregorian Calendar Date Handling.

## dateformat Functionalities

The `dateformat` class defines the format in which a date is output or input.

### Accepted Date Formats:

#### Date Formats:
* **"0"**: No date provided. For output only.
* **"d"**: Single digit date in one digit *(9)*, Double Digit date in two digits *(25)*.
* **"dd"**: All dates in two digits. Single digit dates with leading 0 *(09, 25)*.

#### Month Format:
* **"0"**: Full names of months *(February, November)*. For output only.
* **"m"**: Single digit month in one digit *(2)*, Double Digit month in two digits *(11)*.
* **"mm"**: All months in two digits. Single digit months with leading 0 *(02, 11)*.
* **"mmm"**: First three letters of month name *(Feb, Nov)*. For output only.

#### Year Format:
* **"0"**: No year provided. For output only.
* **"yy"**: Year in last two digits *(61, 16)*.
* **"yyyy"**: Year in four digits *(1961, 2016)*.

### Constructors

* `DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat)` - Three C-strings format with Date Format, Month Format, and Year Format provided. `DateFormat format ("d", "mm", "yyyy")`.

* `DateFormat (const char* format)` - Single C-string format where Date Format, Month Format, and Year Format are separated by ’-’. `DateFormat format ("d-mm-yyyy")`.

* `DateFormat ()` - Creates default `DateFormat` - "dd-mmm-yy".

### Methods

* `char* get_dateFormat () const` - Get Date Format.

* `char* get_monthFormat () const` - Get Month Format.

* `char* get_yearFormat () const` - Get Year Format.

### Usage with `date` Class

To define the format in which `Date` objects are input and output, set the value of the static `format` member as follows:

    DateFormat form ("dd-mm-yyyy");
    Date::setFormat (form);

## date Functionalities

The `date` class gives functionalities to use dates and perform operation on them, in C++ programs.

### Date Data Types

* `Day` - `DXX` representing the XXth Day of the Month, (`D28`, 28th), (`D01`, 1st)
* `Month` - `MXX` representing the XXth Month of the Year, (`M09`, September)
* `Year` - Unsigned Integer values
* `WeekDay` - `Mon` representing Monday
* `WeekNumber` - `WXX` representing the XXth Week of the Year, (`W34`, Week Number 34)

### Constructors

### Methods

### Global Methods

## Using the library

### Downloading the library

### Using the library in a program

Include the following header file in your program:
