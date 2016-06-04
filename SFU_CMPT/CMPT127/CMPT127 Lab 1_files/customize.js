function Get(yourUrl){
    var Httpreq = new XMLHttpRequest(); // a new request
    Httpreq.open("GET",yourUrl,false);
    Httpreq.send(null);
    return Httpreq.responseText;          
}

// var url = window.location.href

var cfg_url = "http://www.cs.sfu.ca/CourseCentral/127/alavergn/config.json"
var me_url = "http://www.cs.sfu.ca/CourseCentral/127/alavergn/lab/me.cgi"

var cfg_json = JSON.parse(Get( cfg_url ));
console.log("semester "+ cfg_json.semester );

var me_json = JSON.parse(Get( me_url ));
console.log("user "+ me_json.username );

// replace template macros with this semester's info
document.body.innerHTML = document.body.innerHTML.replace( /\$CODE/g, cfg_json.code );
document.body.innerHTML = document.body.innerHTML.replace( /\$SVN/g, cfg_json.svnprefix );
document.body.innerHTML = document.body.innerHTML.replace( /\$SEMESTER/g, cfg_json.semester );
document.body.innerHTML = document.body.innerHTML.replace( /\$USER/g, me_json.username );