eg.getDataList=function(min,max){
    var lst=[],n=8;
    for(var i=0;i<n;i++){
        var k=min + parseInt(Math.random()*(max-min));
        lst.push(k+".jpg");
    }
    return lst;
};
eg.cols=eg.getElementsByClassName("col");
eg.colh=[0,0,0,0];
eg.getColMin=function(){
    var min=0,m={};
    for(var i=0;i<4;i++){
        min=parseInt(eg.cols[i].offsetHeight);
        eg.colh[i]=min;
        m[min]=i;
    }
    return eg.cols[m[Math.min.apply(Array,eg.colh)]||0];
}
eg.add=function(dl){
    for(var i in dl){
        var newDiv=document.createElement("div")
        var newImg=document.createElement("img");
            newImg.src=dl[i];
            newDiv.appendChild(newImg);
            newDiv.innerHTML +='<p>['+dl[i]+']</p>';
            eg.getColMin().appendChild(newDiv);
    }
};
eg.scroll=function(){
    window.onscroll=function(){
        var doc=document;
        var top=doc.documentElement.scrollTop || doc.body.scrollTop;
        var winH=doc.documentElement.clientHeight||doc.body.clientHeight;
        if(Math.min.apply(Array,eg.colh)<top+winH){
            eg.add(eg.getDataList(1,35));
        }
    }
}