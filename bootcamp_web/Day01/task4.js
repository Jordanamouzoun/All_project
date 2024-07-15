/*
** EPITECH PROJECT, 2023
** bootcamp_web
** File description:
** task4.js
*/

function getRandomNumber(min, max)
{
    return Math.trunc(Math.random() * (max - min) + min);
}

const min = 1;
const max = 10;
const randomNumber = getRandomNumber(min, max);
console.log(`Random number between ${min} and ${max}: ${randomNumber}`);