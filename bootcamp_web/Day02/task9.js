function calculateAverage(num)
{
    let sum = 0;
    num.forEach(element => {
        sum += element;
    });
    return sum / num.length;
}
const numbers = [1, 2, 3, 4, 5];
const average = calculateAverage(numbers);
console.log(average);