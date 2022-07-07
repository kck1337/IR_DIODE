import numpy as np
def normalize(ir_sensor,scale,zero_centered=True):
    max = int(np.max(ir_sensor))
    min = int(np.min(ir_sensor))
    ir_sensor = scale* ((ir_sensor - min) / (max - min))
    if zero_centered:
        ir_sensor = ir_sensor - 0.5*scale
    return ir_sensor