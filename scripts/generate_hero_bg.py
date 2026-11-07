#!/usr/bin/env python3
"""Generate hero background images for RT-Thread Workshop docs."""

from PIL import Image, ImageDraw
import math


def draw_hexagon(draw, cx, cy, radius, color):
    points = []
    for i in range(6):
        angle = math.pi / 3 * i - math.pi / 6
        px = cx + radius * math.cos(angle)
        py = cy + radius * math.sin(angle)
        points.append((px, py))
    draw.polygon(points, outline=color)


def generate_light_bg():
    W, H = 1920, 600
    img = Image.new("RGB", (W, H), "#f0f4f8")
    draw = ImageDraw.Draw(img)

    # Very soft top-to-bottom gradient
    for y in range(H):
        ratio = y / H
        r = int(242 - 8 * ratio)
        g = int(246 - 6 * ratio)
        b = int(250 - 4 * ratio)
        draw.line([(0, y), (W, y)], fill=(r, g, b))

    # Extremely subtle grid
    grid = (218, 228, 238)
    for x in range(0, W + 80, 80):
        draw.line([(x, 0), (x, H)], fill=grid, width=1)
    for y in range(0, H + 80, 80):
        draw.line([(0, y), (W, y)], fill=grid, width=1)

    # Corner decorations only (no central ellipse)
    hex_color = (195, 210, 220)
    hex_positions = [
        (110, 90, 38), (240, 50, 22), (1700, 80, 45),
        (1810, 200, 28), (80, 520, 30), (1830, 450, 35),
    ]
    for cx, cy, r in hex_positions:
        draw_hexagon(draw, cx, cy, r, hex_color)
        draw_hexagon(draw, cx, cy, r + 6, hex_color)

    # Corner circuit traces
    trace = (185, 200, 215)
    # Top-left
    draw.line([(40, 100), (200, 100)], fill=trace, width=1)
    draw.line([(200, 100), (200, 160)], fill=trace, width=1)
    # Top-right
    draw.line([(1700, 120), (1860, 120)], fill=trace, width=1)
    draw.line([(1700, 120), (1700, 180)], fill=trace, width=1)
    # Bottom-left
    draw.line([(40, 480), (180, 480)], fill=trace, width=1)
    draw.line([(180, 480), (180, 420)], fill=trace, width=1)
    # Bottom-right
    draw.line([(1720, 500), (1880, 500)], fill=trace, width=1)
    draw.line([(1720, 500), (1720, 400)], fill=trace, width=1)

    # Teal accent nodes
    teal = (0, 150, 136)
    nodes = [(40, 100), (200, 100), (200, 160), (1700, 120), (1860, 120),
             (40, 480), (180, 480), (180, 420), (1720, 500), (1880, 500)]
    for x, y in nodes:
        draw.ellipse([(x - 3, y - 3), (x + 3, y + 3)], fill=teal)

    # Scattered particles (mostly edges)
    import random
    random.seed(42)
    for i in range(50):
        x = random.choice([random.randint(20, 400), random.randint(1520, 1900)])
        y = random.randint(20, 580)
        r = random.randint(1, 3)
        draw.ellipse([(x - r, y - r), (x + r, y + r)], fill=teal)

    # Very subtle radial wash in center (barely visible)
    for r in range(600, 0, -20):
        alpha = int(3 * (1 - r / 600))
        x0 = W // 2 - r
        y0 = H // 2 - r // 4
        draw.ellipse([(x0, y0), (x0 + 2 * r, y0 + r)], fill=(240 + alpha, 248, 245))

    img.save("docs/assets/hero_bg_light.jpg", "JPEG", quality=92)
    print("Created: docs/assets/hero_bg_light.jpg")


def generate_dark_bg():
    W, H = 1920, 600
    img = Image.new("RGB", (W, H), "#12121e")
    draw = ImageDraw.Draw(img)

    # Dark gradient
    for y in range(H):
        ratio = y / H
        r = int(18 + (12 - 18) * ratio)
        g = int(18 + (12 - 18) * ratio)
        b = int(30 + (18 - 30) * ratio)
        draw.line([(0, y), (W, y)], fill=(r, g, b))

    # Subtle grid
    grid = (28, 32, 48)
    for x in range(0, W + 80, 80):
        draw.line([(x, 0), (x, H)], fill=grid, width=1)
    for y in range(0, H + 80, 80):
        draw.line([(0, y), (W, y)], fill=grid, width=1)

    # Glowing corner hexagons
    glow = (0, 180, 170)
    hex_positions = [
        (110, 90, 38), (240, 50, 22), (1700, 80, 45),
        (1810, 200, 28), (80, 520, 30), (1830, 450, 35),
    ]
    for cx, cy, r in hex_positions:
        draw_hexagon(draw, cx, cy, r, glow)

    # Glowing traces
    trace = (0, 160, 145)
    trace_glow = (0, 70, 60)
    for y in [100, 480]:
        draw.line([(38, y), (202, y)], fill=trace_glow, width=3)
        draw.line([(40, y), (200, y)], fill=trace, width=1)
        draw.line([(1698, y), (1862, y)], fill=trace_glow, width=3)
        draw.line([(1700, y), (1860, y)], fill=trace, width=1)
    for x in [200, 1700]:
        draw.line([(x, 98), (x, 162)], fill=trace_glow, width=3)
        draw.line([(x, 100), (x, 160)], fill=trace, width=1)

    # Glowing nodes
    bright = (0, 255, 230)
    nodes = [(40, 100), (200, 100), (200, 160), (1700, 120), (1860, 120),
             (40, 480), (180, 480)]
    for x, y in nodes:
        draw.ellipse([(x - 5, y - 5), (x + 5, y + 5)], fill=(0, 80, 72))
        draw.ellipse([(x - 2, y - 2), (x + 2, y + 2)], fill=bright)

    # Floating particles
    import random
    random.seed(142)
    for i in range(60):
        x = random.choice([random.randint(10, 350), random.randint(1570, 1910)])
        y = random.randint(10, 590)
        r = random.randint(1, 4)
        b = random.randint(110, 200)
        draw.ellipse([(x - r, y - r), (x + r, y + r)], fill=(0, b, b - 15))

    # Very subtle center wash (dark teal, barely visible)
    for r in range(600, 0, -20):
        alpha = int(4 * (1 - r / 600))
        x0 = W // 2 - r
        y0 = H // 2 - r // 4
        draw.ellipse([(x0, y0), (x0 + 2 * r, y0 + r)], fill=(16 + alpha, 24 + alpha, 28 + alpha))

    img.save("docs/assets/hero_bg_dark.jpg", "JPEG", quality=92)
    print("Created: docs/assets/hero_bg_dark.jpg")


if __name__ == "__main__":
    generate_light_bg()
    generate_dark_bg()
