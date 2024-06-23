let paragraph = document.querySelectorAll('p')
console.log(paragraph)

window.addEventListener('load',function () {
    
    let delay =1500;
    paragraph.forEach((paragraph,index)=>{
        setTimeout(()=>{
            paragraph.classList.add('visible');
        },delay * (index + 1));
    });
  });
