"""Write a python program to input a date as string in the format DD/MM/YYY. 
split() it into a list of date, month and year. Check whether the given date and months are valid.
 Use an Exception handling method."""

class InvalidDateException(Exception):  # creating an exception for invalid date
    pass
class InvalidMonthException(Exception):  # creating an exception for invalid month
    pass
d=input("ENTER A DATE AS DD/MM/YYYY: ").split("/")  # splitting the date into day,month,year
try:
    if int(d[1])==2:  # date checking for february
        if int(d[2])%4==0:  # if leap year  
            if int(d[0])>29: # date greater than 29
                raise InvalidDateException  # raise exception
        else:
            if int(d[0])>28: # if not leap year, date greater than 28
                raise InvalidDateException  # raise exception
    if int(d[1]) in [1,3,5,7,8,10,12]:
        if int(d[0])>31:  # if date greater than 31
            raise InvalidDateException  # raise exception
    if int(d[1]) in [4,6,9,11]:
        if int(d[0])>30:  # if date greater than 31
            raise InvalidDateException  # raise exception
    else:
        
    if int(d[1])>12:  # if month>12
        raise InvalidMonthException  # raise exception
    print("Valid Date.")
except InvalidDateException:  # handling the excepting
    print("The date is invalid.")
except InvalidMonthException:  # handling the excepting
    print("The month is invalid.")
