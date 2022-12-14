const Pool = require("pg").Pool;

const pool = new Pool({
  user: "postgres",
  password: "root",
  host: "localhost",
  port: 5432,
  database: "postgres"
});
 module.exports = pool;



// var pg = require('pg');
// const { rows } = require('pg/lib/defaults');
// var conString = "postgres://postgres:root@localhost:5432/postgres";
// var client = new pg.Client(conString);
// client.connect();
// console.log("hello");
// var query1 = client.query("SELECT * FROM todo");
// console.log(query1);



// const  {Client}=require("pg");
// const connectDb=async()=>{
// try{
//   const client=new Client(
//     {
//       user:"postgres",
//       host:"localhost",
//       database:"postgres",
//       password:"root",
//       port:5432
//     }
//   )
//   await client.connect()
//   const res=await client.query('select * from todo')
//   console.log(res)
//   await client.end()
// }catch(error){
//   console.log(error);
// }

// }
// connectDb()


// const  {Client}=require("pg");
// const client=new Client(
//       {
//         user:"postgres",
//         host:"localhost",
//         database:"postgres",
//         password:"root",
//         port:5432
//       }
//     )
//   client.connect();
//   client.query('select * from todo',(err,res)=>{
// if(!err){
//   console.log(res);
// }
// client.end();
//   });