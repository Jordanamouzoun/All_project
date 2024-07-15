/*
** EPITECH PROJECT, 2023
** bootcamp_web
** File description:
** task3.js
*/

function findLargestElement(array)
{
    let big = 0;

    for (let a = 0; a < array.length; a++)
        if (array[a] > big)
            big = array[a];
    return big;
}

const array = [5, 2, 9, 1, 7];
const largestElement = findLargestElement(array);
console.log(`The largest element in the array is: ${largestElement}`);