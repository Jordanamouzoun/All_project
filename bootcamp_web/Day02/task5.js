function calculatePower(base, exponent)
{
    if (exponent < 0)
        return -1;
    return Math.pow(base, exponent);
}

const base = 2;
const exponent = 3;
const result = calculatePower(base, exponent);
console.log(result);