/*
** EPITECH PROJECT, 2023
** bootcamp_web
** File description:
** task7.js
*/

function isLeapYear(year)
{
    if (year % 4 == 0) {
        return true;
    } else
        return false
}

const year = 2000;
const isLeap = isLeapYear(year);
console.log(`Is ${year} a leap year? ${isLeap}`);