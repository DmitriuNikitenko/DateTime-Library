# DateTime library

Implement classes to represent dates and times.

## Implementation requirements
* Name of classes: `date`, `time`, `datetime`, `timediff`
* Header file: `datetime.h`
* Implementation file: `datetime.cpp`
* Namespace `DateTime`
* File `main.cc` не менять.

## Class time
Class for representing time of day.

### Constructor
```c++
time(int hour,
     int minute,
     int second);
```
#### Ranges:
* 0 <= hour < 24,
* 0 <= minute < 60,
* 0 <= second < 60.

#### Note
Throw an `std::invalid_argument` exception if the constructor arguments are specified incorrectly.
For example, `throw std::invalid_argument("hours must be between 0 and 23");`

### Available Methods
```c++
int hour() const;      // Get the number of hours
int minute() const;    // Get the number of minutes
int second() const;    // Get the number of seconds

void add_hours(int nb_hours);      // Add the specified number of hours
void add_minutes(int nb_minutes);  // Add the specified number of minutes
void add_seconds(int nb_seconds);  // Add the specified number of seconds
```
### External function

```c++
std::string to_string(const time&);  // Convert to a string in format "HH:mm:ss"
```

#### String format

| Specifier | Description                                  |
| --------- | -------------------------------------------- |
| HH        | Hours in 24-hour format from 00 to 23        |
| mm        | Minutes from 00 to 59                        |
| ss        | Seconds from 00 to 59                        |

### Supported operators
```c++
time tm1 = time(12, 50, 0);
time tm2 = time(13, 40, 0);
time tm3 = tm1;
```
| Operator     | Description            | Usage example                    |
| ------------ | ---------------------- | -------------------------------- |
| time == time | Equality operator      | `assert(tm1 == tm3);`            |
| time != time | Inequality operator    | `assert(tm1 != tm2);`            |
| time < time  | Less operator          | `assert(tm1 < tm2);`             |
| time <= time | Less equal operator    | `assert(tm1 <= tm2);`            |
| time > time  | Greater operator       | `assert(tm2 > tm3);`             |
| time >= time | Greater equal operator | `assert(tm2 >= tm3);`            |
| time - time  | Minus operator         | `timediff ts1 = tm2 - tm1;`<br>`assert(ts.minutes() == 50);`<br>`assert(ts.hours() == 0);` |

## Class date
A class for representing a date. 

### Constructor
```c++
date(int year,
     int month,
     int day);
```

#### Note
When constructor arguments are invalid, throw a `std::invalid_argument` exception.

### Available methods
```c++
int year() const;            // Get the year    
int month() const;           // Get the month 
int day() const;             // Get the day
weekday weekday() const;     // Get the day of the week for the date
bool is_leapyear() const;    // true if the year is leap, otherwise false

void add_days(int nb_days);  // Add the given number of days

date next() const;           // Get the date of the next day
date prev() const;           // Get the date of the previous day

static bool is_leapyear(int year); // Check if a year is leap 
```

### External function

```c++
std::string to_string(const date&);  // Convert to a string in format "yyyy.MM.dd"
```

#### String format

| Specifier | Description                             |
| --------- | --------------------------------------- |
| yyyy      | Year                                    |
| MM        | Month from 01 to 12                     |
| dd        | Day of month from 01 to 31              |

### Supported operators
```c++
date dt1 = date(2025, 2, 11);
date dt2 = date(2025, 2, 12);
date dt3 = dt1;
```
| Operator     | Description             | Usage example                   |
| ------------ | ----------------------- | -------------------------------- |
| date == date | Equality operator       | `assert(dt1 == dt3);`           |
| date != date | Inequality operator     | `assert(dt1 != dt2);`           |
| date < date  | Less operator           | `assert(dt1 < dt2);`            |
| date <= date | Less equal operator     | `assert(dt1 <= dt2);`           |
| date > date  | Greater operator        | `assert(dt2 > dt3);`            |
| date >= date | Greater equal operator  | `assert(dt2 >= dt3);`           |
| date - date  | Minus operator          | `timediff ts = dt2 - dt1;` <br> `assert(ts.days() == 1)`|
| ++date       | Pre-increment operator  | `assert(++dt1 == dt2);`         |
| date++       | Post-increment operator | `dt1++; assert(dt1 == dt2);`    |
| --date       | Pre-decrement operator  | `assert(--dt2 == dt3);`         |
| date--       | Post-decrement operator | `dt2--; assert(dt2 == dt3);`    |


## Class datetime
A class for representing date and time. 

### Constructors
```c++
datetime(int year,
         int month,
         int day,
         int hour = 0,
         int minute = 0,
         int second = 0);
datetime(const date & dt,
         const time & tm);
```

#### Note
When arguments are invalid, throw a `std::invalid_argument` exception.  
For example:  
`throw std::invalid_argument("hours must be between 0 and 23");`

### Available methods
```c++
int year() const;
int month() const;
int day() const;
int hour() const;
int minute() const;
int second() const;
weekday weekday() const;
bool is_leapyear() const;          // true if the year is leap, otherwise false

void add_days(int nb_days);        // Add the given number of days
void add_hours(int nb_hours);      // Add the given number of hours
void add_minutes(int nb_minutes);  // Add the given number of minutes
void add_seconds(int nb_seconds);  // Add the given number of seconds

static bool is_leapyear(int year); // Check if a year is leap 
```

### External function

```c++
std::string to_string(const datetime&);  // Convert to a string in format "yyyy.MM.dd HH:mm:ss"
```

#### String format

| Specifier | Description                                  |
| --------- | -------------------------------------------- |
| yyyy      | Year                                         |
| MM        | Month from 01 to 12                          |
| dd        | Day of month from 01 to 31                   |
| HH        | Hours in 24-hour format from 00 to 23        |
| mm        | Minutes from 00 to 59                        |
| ss        | Seconds from 00 to 59                        |

### Supported operators
```c++
datetime dt1 = datetime(2025, 2, 11, 12, 0, 0);
datetime dt2 = datetime(2025, 2, 12, 14, 1, 0);
datetime dt3 = dt1;
timediff ts(1, 2, 1, 0);
```

| Operator             | Description            | Usage example                  |
| -------------------- | ---------------------- | ------------------------------ |
| datetime == datetime | Equality operator      | assert(dt1 == dt3);            |
| datetime != datetime | Inequality operator    | assert(dt1 != dt2);            |
| datetime < datetime  | Less operator          | assert(dt1 < dt2);             |
| datetime <= datetime | Less equal operator    | assert(dt1 <= dt2);            |
| datetime > datetime  | Greater operator       | assert(dt2 > dt3);             |
| datetime >= datetime | Greater equal operator | assert(dt2 >= dt3);            |
| datetime - datetime  | Minus operator         | timediff ts = dt2 - dt1;<br>assert(ts.days() == 1);<br>assert(ts.hours() == 2); |
| datetime - ts        | Minus operator         | assert(dt2 - ts == dt1)        |
| datetime + ts        | Plus operator          | assert(dt1 + ts == dt2)        |


## Class timediff
A class for representing the difference between dates and times. 

### Constructor

```c++
timediff(int days, int hours, int minutes, int seconds);
```

#### Note
When arguments are invalid, throw a `std::invalid_argument` exception.  
For example:  
`throw std::invalid_argument("hours must be between -23 and 23");`  
or  
`throw std::invalid_argument("all arguments must have the same sign");`

### Available methods
```c++
int days() const;            // Get number of days
int hours() const;           // Get number of hours
int minutes() const;         // Get number of minutes   
int seconds() const;         // Get number of seconds
int total_hours() const;     // Get total number of hours (including days)
int total_minutes() const;   // Get total number of minutes
int total_seconds() const;   // Get total number of seconds
```

### Supported operators
```c++
timediff ts1(1, 2, 3, 10);
timediff ts2(1, 0, 4, 0);
timediff ts3 = ts1;
```

| Operator             | Description            | Usage example                  |
| -------------------- | ---------------------- | ------------------------------ |
| timediff == timediff | Equality operator      | assert(ts1 == ts3);            |
| timediff != timediff | Inequality operator    | assert(ts1 != ts2);            |
| timediff < timediff  | Less operator          | assert(ts2 < ts1);             |
| timediff <= timediff | Less equal operator    | assert(ts2 <= ts1);            |
| timediff > timediff  | Greater operator       | assert(ts1 > ts2);             |
| timediff >= timediff | Greater equal operator | assert(ts1 >= ts2);            |
| timediff >= timediff | Greater equal operator | assert(ts1 >= ts2);            |
| timediff + timediff  | Plus operator          | assert(ts1 >= ts2);            |
| timediff - timediff  | Minus operator         | assert(ts1 >= ts2);            |
