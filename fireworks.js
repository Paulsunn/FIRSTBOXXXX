const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

function random(min, max) {
    return Math.random() * (max - min) + min;
}

class Firework {
    constructor(x, y, targetX, targetY) {
        this.x = x;
        this.y = y;
        this.targetX = targetX;
        this.targetY = targetY;
        this.distanceToTarget = Math.sqrt((targetX - x) ** 2 + (targetY - y) ** 2);
        this.angle = Math.atan2(targetY - y, targetX - x);
        this.speed = 2;
        this.acceleration = 1.05;
        this.brightness = random(50, 70);
        this.traces = [];
    }

    update() {
        this.speed *= this.acceleration;
        const velocityX = Math.cos(this.angle) * this.speed;
        const velocityY = Math.sin(this.angle) * this.speed;
        this.x += velocityX;
        this.y += velocityY;

        if (Math.abs(this.x - this.targetX) < this.speed && Math.abs(this.y - this.targetY) < this.speed) {
            this.createParticles();
            return true;
        }

        this.traces.push([this.x, this.y]);
        if (this.traces.length > 5) {
            this.traces.shift();
        }
        return false;
    }

    draw() {
        ctx.beginPath();
        ctx.moveTo(this.traces[0][0], this.traces[0][1]);
        for (let i = 1; i < this.traces.length; i++) {
            ctx.lineTo(this.traces[i][0], this.traces[i][1]);
        }
        ctx.strokeStyle = `hsl(${random(0, 360)}, 100%, ${this.brightness}%)`;
        ctx.stroke();
    }

    createParticles() {
        for (let i = 0; i < 150; i++) {  // 增加粒子数量
            particles.push(new Particle(this.targetX, this.targetY));
        }
    }
}

class Particle {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.angle = random(0, Math.PI * 2);
        this.speed = random(2, 14);  // 增加粒子的速度范围
        this.friction = 0.95;
        this.gravity = 1.2;
        this.brightness = random(50, 80);
        this.alpha = 1;
        this.decay = random(0.01, 0.02);  // 调整粒子的消失速度
    }

    update() {
        this.speed *= this.friction;
        this.x += Math.cos(this.angle) * this.speed;
        this.y += Math.sin(this.angle) * this.speed + this.gravity;
        this.alpha -= this.decay;

        return this.alpha <= this.decay;
    }

    draw() {
        ctx.beginPath();
        ctx.arc(this.x, this.y, 3, 0, Math.PI * 2);  // 增大粒子的半径
        ctx.fillStyle = `hsla(${random(0, 360)}, 100%, ${this.brightness}%, ${this.alpha})`;
        ctx.fill();
    }
}

const fireworks = [];
const particles = [];

function loop() {
    requestAnimationFrame(loop);
    ctx.globalCompositeOperation = 'destination-out';
    ctx.fillStyle = 'rgba(0, 0, 0, 0.5)';
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.globalCompositeOperation = 'lighter';

    fireworks.forEach((firework, index) => {
        if (firework.update()) {
            fireworks.splice(index, 1);
        }
        firework.draw();
    });

    particles.forEach((particle, index) => {
        if (particle.update()) {
            particles.splice(index, 1);
        }
        particle.draw();
    });
}

loop();

canvas.addEventListener('mousedown', (event) => {
    const x = event.clientX;
    const y = event.clientY;
    fireworks.push(new Firework(canvas.width / 2, canvas.height, x, y));
});

canvas.addEventListener('contextmenu', (event) => {
    event.preventDefault();
    const x = event.clientX;
    const y = event.clientY;
    fireworks.push(new Firework(canvas.width / 2, canvas.height, x, y));
});

window.addEventListener('resize', () => {
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
});