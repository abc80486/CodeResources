function checkRealName(){
    var str=form1.realName.value;
    if(str==""){
        alert("请输入真实名字！");form1.realName.focus();return;
    }else{
        var objExp=/[\u4E00-\u9FA5]{2,}/;
        if(objExp.test(str)==true){
            alert("您输入的姓名正确！");
        }else{
            alert("您输入的姓名有误！");
        }
    }
}