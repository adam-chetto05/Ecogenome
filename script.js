let popup = document.querySelector('.popup')
let btn_show = document.querySelector('.btn-1')
let koulchi = document.querySelector('.koulchi')

btn_show.addEventListener("click", function() {
    console.log('Button clicked'); 
    popup.classList.toggle('active');
    koulchi.classList.toggle('blur')
});


// btn2 pour fermer popup

let btn_show2 = document.querySelector('.btn-2')
btn_show2.addEventListener("click", function() {
    console.log('Button clicked'); 
    popup.classList.toggle('active');
    koulchi.classList.toggle('blur')   
});

