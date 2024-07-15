function isPerfectSquare(num)
{
    const sqrt = Math.sqrt(num);
    if (sqrt == Math.trunc(sqrt))
        return true;
    else 
        return false;
}

const num1 = 16;
console.log(isPerfectSquare(num1));  // true

const num2 = 25;
console.log(isPerfectSquare(num2));  // true

const num3 = 10;
console.log(isPerfectSquare(num3));  // false