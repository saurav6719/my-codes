let myPromise = new Promise(function exec(resolve, reject){
        setTimeout(function givevalue(){
            let x = 5;
            if(x%2===0){
                resolve("successful");
            } else{
                reject("failed");
            }

            console.log("after resolving or rejecting");
        }, 3000);

        console.log("promise done");
        
    });

// Consuming the Promise
myPromise
    .then(function fulfillmenthandler(){
        console.log("success");
    } , function rejectionhandler(){
        console.log("failed");
    });
