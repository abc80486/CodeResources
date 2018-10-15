eg.data=[
    /*
    ["p (1).png","thumb (1).png"],
    ["p (2).png","thumb (2).png"],
    ["p (3).png","thumb (3).png"],
    ["p (4).png","thumb (4).png"],
    ["p (5).png","thumb (5).png"],
    ["p (6).png","thumb (6).png"],
    ["p (7).png","thumb (7).png"],
    ["p (8).png","thumb (8).png"],
    ["p (9).png","thumb (9).png"],
    ["p (10).png","thumb (10).png"],
    ["p (11).png","thumb (11).png"],
    ["p (12).png","thumb (12).png"],
    ["p (13).png","thumb (13).png"],
    ["p (14).png","thumb (14).png"]
    
   ["p (1).png","p (1).png"],
    ["p (2).png","p (2).png"],
    ["p (3).png","p (3).png"],
    ["p (4).png","p (4).png"],
    ["p (5).png","p (5).png"],
    ["p (6).png","p (6).png"],
    ["p (7).png","p (7).png"],
    ["p (8).png","p (8).png"],
    ["p (9).png","p (9).png"],
    ["p (10).png","p (10).png"],
    ["p (11).png","p (11).png"],
    ["p (12).png","p (12).png"],
    ["p (13).png","p (13).png"],
    ["p (14).png","p (14).png"]
   */
  "p (1).png",
    "p (2).png",
    "p (3).png",
    "p (4).png",
    "p (5).png",
    "p (6).png",
    "p (7).png",
    "p (8).png",
    "p (9).png",
    "p (10).png",
    "p (11).png",
    "p (12).png",
    "p (13).png",
    "p (14).png"
];
eg.showNumber=0;
eg.groupNumber=1;
eg.groupSize=6;
eg.showThumb=function(group){
    var ul=eg.$("smallPhotosList");
    ul.innerHTML='';
    var start=(group-1)*eg.groupSize;
    var end=group*eg.groupSize;
    for(var i=start;(i<end&&i<eg.data.length);i++){
        var li=document.createElement("li");
        li.innerHTML='<img src="'+eg.data[i]+'" id="p ('+i+')"width="80"height="40"/>';
        (function(i){
            eg.addListener(li,"click",function(){
                eg.showNumber=i;
                eg.showBig();
            })
        })(i);
        ul.appendChild(li);
    }
};
eg.showBig=function(){
    eg.$("bigPhotoSrc").src=eg.$("p ("+eg.showNumber+")").src;
};
eg.init=function(){
    eg.showThumb(1);
    eg.addListener(eg.$("next"),"click",function(){
        eg.nextThumb();
    });
    eg.addListener(eg.$("prve"),"click",function(){
        eg.prveThumb();
    });
};
eg.nextThumb=function(){
    if((eg.groupNumber*eg.groupSize)+1<=eg.data.length){
        eg.showThumb(eg.groupNumber+1);
        eg.showNumber=eg.groupNumber*eg.groupSize;
        eg.showBig();
        eg.groupNumber++;
    }
};
eg.prveThumb=function(){
    if(eg.groupNumber-1>=1){
        eg.showThumb(eg.groupNumber-1);
        eg.groupNumber--;
        eg.showNumber=eg.groupNumber*eg.groupSize-eg.groupSize;
        eg.showBig();
    }
};
eg.init();