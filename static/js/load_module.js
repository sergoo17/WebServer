let statusElement = document.getElementById('status');
let progressElement = document.getElementById('progress');
let spinnerElement = document.getElementById('spinner');

var Module = {
    locateFile: function (path, prefix) {
        return '/static/wasm/' + path;
    },
    print: (function() {
        let element = document.getElementById('output');
        if (element) element.value = '';
        return function(text) {
            if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');
            console.log(text);
            if (element) {
                element.value += text + "\n";
                element.scrollTop = element.scrollHeight;
            }
        };
    })(),
    canvas: (() => {
        let canvas = document.getElementById('canvas');
        canvas.addEventListener("webglcontextlost", (e) => {
            alert('WebGL context lost. You will need to reload the page.');
            e.preventDefault();
            }, false);

        return canvas;
    })(),
    setStatus: (text) => {
        if (!Module.setStatus.last) Module.setStatus.last = { time: Date.now(), text: '' };
        if (text === Module.setStatus.last.text) return;
        let m = text.match(/([^(]+)\((\d+(\.\d+)?)\/(\d+)\)/);
        let now = Date.now();
        if (m && now - Module.setStatus.last.time < 30) return;

        Module.setStatus.last.time = now;
        Module.setStatus.last.text = text;
        if (m) {
            text = m[1];
            progressElement.value = parseInt(m[2])*100;
            progressElement.max = parseInt(m[4])*100;
            progressElement.hidden = false;
            spinnerElement.hidden = false;
        } else {
            progressElement.value = null;
            progressElement.max = null;
            progressElement.hidden = true;
            if (!text) spinnerElement.style.display = 'none';
        }
        statusElement.innerHTML = text;
    },
    totalDependencies: 0,
    monitorRunDependencies: (left) => {
        this.totalDependencies = Math.max(this.totalDependencies, left);
        Module.setStatus(left ? 'Preparing... (' + (this.totalDependencies-left) + '/' + this.totalDependencies + ')' : 'All downloads complete.');
    }
};
Module.setStatus('Downloading...');
window.onerror = (event) => {
    Module.setStatus('Exception thrown, see JavaScript console');
    spinnerElement.style.display = 'none';
    Module.setStatus = (text) => {
        if (text) console.error('[post-exception status] ' + text);
    };
};