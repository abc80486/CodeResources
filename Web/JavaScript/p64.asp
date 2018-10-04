<%@language="javascript"%>
<%
var names=["z3f","admin","text","anna","cindy","diana"];
var q=Request.QueryString("username");
var has=0;
for(var i=0;i<names.length;i++){
    if(names[i]==q){
        has=1;break;
    }
}
if(has==1){
    Response.Write(q+"已注册，请换其他用户名")；
}else{
    Response.Write(q+"用户名可用")；
}
%>