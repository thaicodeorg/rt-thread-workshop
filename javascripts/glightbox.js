(function () {
    "use strict";

    function wrapImages() {
        var content = document.querySelector(".md-content") || document.querySelector(".md-content__inner");
        if (!content) return;

        var images = content.querySelectorAll("img");
        images.forEach(function (img) {
            // Skip if already wrapped
            if (img.parentNode && img.parentNode.tagName === "A") return;
            // Skip inside code blocks
            if (img.closest("pre") || img.closest("code")) return;

            var src = img.getAttribute("src");
            if (!src) return;

            var a = document.createElement("a");
            a.href = new URL(src, window.location.href).href;
            a.className = "glightbox";
            a.setAttribute("data-glightbox", "");

            img.parentNode.insertBefore(a, img);
            a.appendChild(img);
        });
    }

    function initLightbox() {
        wrapImages();
        if (typeof GLightbox !== "undefined") {
            // Avoid double-init: GLightbox stores instance; destroy old one first
            GLightbox({
                selector: ".glightbox",
                touchNavigation: true,
                loop: true,
                zoomable: true,
                draggable: true,
            });
        }
    }

    // Run once DOM is ready
    function run() {
        initLightbox();
    }

    if (document.readyState === "loading") {
        document.addEventListener("DOMContentLoaded", run);
    } else {
        run();
    }

    // Re-init on Material instant navigation
    // Listen for a small delay after popstate + intercept mdx/swup transitions
    window.addEventListener("popstate", function () {
        setTimeout(initLightbox, 150);
    });

    // Use MutationObserver to catch content swaps (most robust for instant nav)
    var contentArea = document.querySelector(".md-content");
    if (contentArea && typeof MutationObserver !== "undefined") {
        new MutationObserver(function () {
            setTimeout(initLightbox, 100);
        }).observe(contentArea, { childList: true, subtree: true });
    }

    // Fallback: hook into document.body for later content injection
    document.addEventListener("readystatechange", function () {
        if (document.readyState === "complete") {
            setTimeout(initLightbox, 100);
        }
    });
})();
