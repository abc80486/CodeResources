<%@language="javascript"%>
<%
var names=["z3f","admin","test","anna","cindy","diana"];
var q=Request.QueryString("username");
var has=0;
for(var i=0;i<names.length;i++){
    if(names[i]==q){
        has=1;
        break;
    }
}
if(has==1){
    Response.Write("{success:false}");
}
else{
    Response.Write("{success:true}");
}
%>