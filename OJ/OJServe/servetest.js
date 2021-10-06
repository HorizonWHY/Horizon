'use strict'

var http = require('http');
var url = require('url');
var fs = require('fs');
var runfile = require('child_process');

//运行错误代码库
var ErrorCode ={
    '3221225477' : '访问越界',
}

var server = http.createServer(function(request,response){
    //console.log(request);
    var args = url.parse(request.url,true);
    var bug = args.query.bug;
    var testarg = args.query.testarg;
    
    response.setHeader('Content-Type','text/html;charset=utf-8');
    //避免浏览器保护
    response.setHeader('Access-Control-Allow-Origin','*');
    response.setHeader('Access-Control-Allow-Headers','X-Requested-With');
    response.setHeader('Access-Control-Allow-Methods','PUT,POST,GET,DELETE,OPTIONS');
    response.setHeader('Access-Control-Allow-Headers','Content-Type, Content-Length, Authorization, Accept, X-Requested-With , yourHeaderFeild');


 //   console.log(request.url); //////
    if(request.url!='/favicon.ico')
    {
        if(bug===undefined)
        {
            console.log('NMSL');
            response.end('NMSL');
        }
        else
        {
            console.log(bug);
           // response.end(bug);
            fs.writeFile('NMSL.c',bug,function(err){
                console.log(err);
                //调用文件
                if(err===null)
                {
                    //执行cmd
                    runfile.exec('gcc -Wall -Wextra C:/Users/HorizonWHY/Desktop/Web/OJServe/NMSL.c',function(error,stdout,stuerr){
                        //console.log(error.code); //errorlevel 判断成功与否
                        //console.log(stdout);
                       //console.log(stuerr);
                       
                        if(error!=null) //编译失败
                        {
                            
                            var res = stuerr.replace(/C\:\/Users\/HorizonWHY\/Desktop\/Web\/OJServe\/NMSL\.c\:/g,'');
                           
                           // console.log(res);
                            response.end(res);
                        }
                        else
                        {
                            if(stuerr!=null)
                            {
                                var wares = '\n警告:\n'+stuerr;
                            }

                            //重定向 exe < input
                            runfile.exec('C:/Users/HorizonWHY/Desktop/Web/OJServe/a.exe ',{timeout:1000},function(RunError,RunStdout,RunStuerr){
                                console.log(RunError);
                            if(RunError!=null)
                            {
                                runfile.exec('TASKKILL /F /IM a.exe');
                                if(RunError.signal==='SIGTERM')
                                {
                                    response.end('Time Out');
                                }
                                else
                                {
                                    response.end(ErrorCode[RunError.code]);
                                }
                
                            }
                            else
                            {

                                response.end(RunStdout+wares);
                            }
                               
                            });
                        }

                     // runfile.exec('C:/Users/HorizonWHY/Desktop/Web/OJServe/a.exe');
                    });
                }
            });
        }

    }

    
});

server.listen(8080);


