OPACUserCSS
-----------

.bookcover {
    float:none;
}

.bookcover {
    width:150px;
    height:220px;
    position:relative;
}

.bookcover img {
    object-fit:cover;
    border-radius:8px;
}

.generated-cover {
    position:absolute;
    inset:0;
    display:flex;
    align-items:center;
    justify-content:center;
    padding:12px;
    text-align:center;
    font-weight:600;
    line-height:1.2;
    border-radius:8px;
    background:linear-gradient(135deg,#6b4db5,#4b2e83);
    color:white;
}

.bookcover img ~ .generated-cover {
    display:none;
}

.cover-slider img ~ .generated-cover {
    display:none;
}

.bookcover:has(img) .generated-cover {
    display:none;
}


OPACUserJS
-----------

document.querySelectorAll(".generated-cover").forEach(el => {

    let title = el.dataset.title || "book";

    let hash = 0;
    for (let i = 0; i < title.length; i++) {
        hash = title.charCodeAt(i) + ((hash << 5) - hash);
    }

    let n = Math.abs(hash);

    let hue = 220 + (n % 60);

    let sat = 55 + (n % 15);
    let light = 40 + (n % 10);

    let hue2 = hue + 15;

    el.style.background = `linear-gradient(
        135deg,
        hsl(${hue}, ${sat}%, ${light + 10}%),
        hsl(${hue2}, ${sat + 5}%, ${light - 5}%)
    )`;

});

document.querySelectorAll(".bookcover").forEach(el => {
    if (!el.querySelector("img")) {
        el.classList.add("no-cover");
    }
});
