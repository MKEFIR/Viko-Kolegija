$$('.image-slider').forEach(function(slider) {
var div = document.createElement('div');
var img = slider.querySelector('img');
slider.insertBefore(img, div);
div.appendChild(img);
// Create the slider
var range = document.createElement('input');
range.type = 'range';
range.oninput = function() {
div.style.width = this.value + '%';
};
slider.appendChild(range);
});