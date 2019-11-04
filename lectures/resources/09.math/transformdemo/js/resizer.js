Resizer = {
    installHandler: function installHandler(canvas) {
        function onresize() {
                canvas.width = window.innerWidth;
                canvas.height = window.innerHeight;
                window.aspect = canvas.width / canvas.height;
        };
        onresize();
        window.onresize = onresize;
    }
}