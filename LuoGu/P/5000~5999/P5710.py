num = int(input())
feat1 = not(num & 1)
feat2 = num > 4 and num <= 12
print(f"{int(feat1 & feat2)} {int(feat1 | feat2)} {int((feat1 and (not(feat2))) or (not(feat1) and feat2))} {int(not(feat1) and not(feat2))}")
