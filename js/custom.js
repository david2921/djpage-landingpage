$(function(){
	$('[data-toggle="tooltip"]').tooltip({
		placement: "bottom",
	});
});
$('a[href*=#]:not([href=#])').not('#myCarousel a .modal-trigger a, .panel a').click(function(o){
    if (location.pathname.replace(/^\//, '') == this.pathname.replace(/^\//, '') || location.hostname.replace(/^\//, '') == this.hostname.replace(/^\//, '')) {
    
    var target= $(this.hash);
    target = target.length ? target : $('[name=]' + this,hash.slice(1)+ ']');
    if (target.length){
        if ($(".navbar").css("position") == "fixed"){
            $('html,body').animate({
                scrollTop:target.offset().top -72
            },1000,'swing');
        } else {
            $('html,body').animate({
                scrollTop:target.offset().top
            },1000,'swing');
        }
        return false;
    }
    }
});