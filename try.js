let arr = [1, 7, 41, 38, 24];

function cmp(a, b){
    return (a - b);
}

arr.sort(cmp);
console.log(arr);