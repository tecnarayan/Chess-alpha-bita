import torch
import numpy as np
import torch.nn as nn
import chess
import random
import time

tick_ = 0
tock_ = 0
max_depth = 1

board_1 = chess.Board()

class Node:
    def __init__(self , state ,move_ ,depth , move_maker , parent = None):
        self.depth = depth
        self.move_ = move_
        self.parent = parent
        self.move_maker = move_maker
        self.state = state
        self.visits = 0
        self.value = 0
        self.children = []
        self.children_discovered = 0

    def insert_child(self , node):
        self.children_discovered = 1
        node.parent = self
        self.children.append(node)

    def probablity_update(self , val):
        self.visits +=1 
        self.value += val
        if self.parent is not None:
            self.parent.probablity_update(val)

def simulation_play_random(node):
    rollouts = 1
    sum = 0
    for _ in range(rollouts):
        board = node.state.copy()
        for _ in range(200):
            moves = list(board.legal_moves)
            random_move = random.choice(moves)
            uci_move = board.uci(random_move)
            board.push_uci(uci_move)

            if board.is_checkmate():
                #print(board)
                if board.turn == chess.WHITE:
                    #sum += 0
                    break
                else:
                    sum += 1
                    break
                
            if board.is_stalemate() or board.is_insufficient_material():
                # #print(board)
                # sum += 0
                break
        # #print(board)
        # sum += 0
    return (sum/rollouts)

def simulation_play_NET(node):
    pass
        
    
PARENT = Node(board_1 ,"" ,1 , 1)

# for _ in range(10):
#     print(simulation_play_random(PARENT))

def MCTS_MOVE_MAKER(parent_node):
    global tock_ , tick_
    tock_ = time.time()
    if tock_ - tick_ > 120 :
        return
    board_parent = parent_node.state
    if parent_node.children_discovered == 0:
        moves = list(board_parent.legal_moves)
        for move in moves:
            move = board_parent.uci(move)
            board_child = board_parent.copy()
            board_child.push_uci(move)
            if parent_node.move_maker == 1:
                node = Node(board_child ,move ,parent_node.depth +1 , -1)
            else:
                node = Node(board_child ,move ,parent_node.depth +1 , 1)
            global max_depth
            if max_depth < parent_node.depth + 1:
                max_depth = parent_node.depth +1
            parent_node.insert_child(node)
        random_node = random.choice(parent_node.children)
        r = simulation_play_random(random_node)
        random_node.probablity_update(r)
        return

    else:
        UCB = []
        for child in parent_node.children:
            if child.visits == 0:
                r = simulation_play_random(child)
                child.probablity_update(r)
                return
            elif child.move_maker != 1:
                x = (child.value/child.visits) + 1.4142*np.sqrt(np.log(child.parent.visits)/child.visits)
            else:
                x = 1 - (child.value/child.visits) + 1.4142*np.sqrt(np.log(child.parent.visits)/child.visits)
            UCB.append(x)
        MCTS_MOVE_MAKER(parent_node.children[np.argmax(UCB)])

    

def PLAY():
    global PARENT , tick_ , tock_
    while(True):
        tick_ = time.time()
        while True:
            MCTS_MOVE_MAKER(PARENT)
            tock_ = time.time()
            if tock_ - tick_ > 120:
                break
        P = []
        for child in PARENT.children:
            x = (child.value/child.visits)
            P.append(x)
        move_arg = np.argmax(P)
        PARENT.children = PARENT.children[move_arg : move_arg+1]
        PARENT = PARENT.children[0]
        print("-----------------------------------------------")
        print(PARENT.state)
        print("-----------------------------------------------")
        print(f"DEPTH : {max_depth - PARENT.depth}")
        print("-----------------------------------------------")
        print(f"WIN PROBABLITY : {np.max(P)}")
        print("-----------------------------------------------")
        print(PARENT.move_)
        print("-----------------------------------------------")
        user_move = input("uci format move ->")
        arg = 0
        for i , a in enumerate(PARENT.children):
            if a.move_ == user_move:
                arg = i
                break
        PARENT.children = PARENT.children[arg : arg+1]
        PARENT = PARENT.children[0]


PLAY()




    

