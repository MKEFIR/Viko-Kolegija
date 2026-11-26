
  document.querySelectorAll('[data-drag-scroll]').forEach((el) => {
    let down = false, startX = 0, startScroll = 0, moved = false;

    el.addEventListener('pointerdown', (e) => {
      if (e.pointerType !== 'mouse') return;
      down = true;
      moved = false;
      startX = e.clientX;
      startScroll = el.scrollLeft;
      el.style.scrollSnapType = 'none';
      el.style.scrollBehavior = 'auto';
    });

    window.addEventListener('pointermove', (e) => {
      if (!down) return;
      const dx = e.clientX - startX;
      if (Math.abs(dx) > 5) moved = true;
      el.scrollLeft = startScroll - dx;
    });

    window.addEventListener('pointerup', () => {
      if (!down) return;
      down = false;
      el.style.scrollSnapType = '';
      el.style.scrollBehavior = '';
    });

    el.addEventListener('click', (e) => {
      if (moved) e.preventDefault();
    }, true);
  });
