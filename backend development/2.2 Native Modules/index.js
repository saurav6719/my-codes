const fs=require("fs");
// fs.writeFile("hello.txt", "hello saurav", (err)=>{
//     if (err) throw err;
//     console.log("the file has been saved");
// })

fs.readFile("hello.txt", "utf8", (err,data)=>{
    if (err) throw err;
    console.log(data);
})