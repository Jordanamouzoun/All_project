/*
** EPITECH PROJECT, 2023
** bootcamp_web
** File description:
** task1.js
*/

function factorial(nbr)
{
    if (nbr == 0)
        return 1;
    else if (nbr < 0)
        return -1;
    else
        return (nbr * factorial(nbr - 1));
}

const number = 0;
const result = factorial(number);
console.log(`The factorial of ${number} is ${result}`);