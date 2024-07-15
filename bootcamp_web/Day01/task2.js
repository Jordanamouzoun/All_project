/*
** EPITECH PROJECT, 2023
** bootcamp_web
** File description:
** task2.js
*/

function isPrime(n)
{
    if (n == 0 || n == 1)
        return "false";
    const v = 0;
    for (let a = 2; a < n; a++) {
        if (n % a == 0)
            return "false";
    }
    return "true";
}

const number = 17;
const isNumberPrime = isPrime(number);
console.log(`Is ${number} prime? ${isNumberPrime}`);