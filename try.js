let myPromise = new Promise(function exec(resolve, reject){
        setTimeout(function givevalue(){
            let x = 5;
            if(x%2===0){
                resolve("successful");
            } else{
                reject("failed");
            }

            console.log("doing synchrounous job inside set timeout ");


            for(let i =0;i<10000000000; i++){}

            console.log("ending synchrounous job inside set timeout");

            console.log("after resolving or rejecting");
        }, 1000);

        console.log("promise done");
        
    });

// Consuming the Promise
myPromise
    .then(function fulfillmenthandler(){
        console.log("success");
    } , function rejectionhandler(){
        console.log("failed");
    });

console.log("doing synchronous job");
for(let i= 0; i<10000000000; i++) {}

console.log("Ending synchrounous job");