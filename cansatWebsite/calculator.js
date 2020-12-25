
var  masa = document.getElementById('masaCansat');
var  velocidad = document.getElementById('velocidad');
var forma = document.getElementById('Forma');
var coeficienteArrastre = 0;
var formulario = document.getElementsByName('formulario')[0];
var elementos = formulario.elements;
var button = document.getElementById('btn');
var result = document.getElementById('resultado');
var area = 0;

var mostrarResultado = function(coeficienteArrastre){
    var area1  = 2 * masa.value * 9.8;

    var area2 =  coeficienteArrastre * velocidad.value * velocidad.value * 1.2754;
    area = (area1/area2) *10;
    result.innerHTML = area;
};

var validar =  function(e)
{ 

    if(masa.value > 350 || masa.value < 300)
    {
        result.innerHTML = "Introduce las variables";
        alert("Introduce una masa entre 300 y 350 gramos");
        e.preventDefault();

    } else if(velocidad.value > 11 || velocidad.value<8)
    {
        result.innerHTML = "Introduce las variables";
        alert("Introduce una velocidad valida");
        e.preventDefault();

    }else{
 
        switch(forma.value){
          case "Cruzado":
              coeficienteArrastre = 0.7;
              break;  
          case "Hexagonal":
                coeficienteArrastre = 0.77;
                break;
          case "SemiEsferico":
              coeficienteArrastre = 0.69;
              break; 
          case "Parapente":
              coeficienteArrastre = 0.92;
              break;     
        default:
            break;
        } 
        mostrarResultado(coeficienteArrastre);
        e.preventDefault();
    }
    
};

formulario.addEventListener("submit", validar);
