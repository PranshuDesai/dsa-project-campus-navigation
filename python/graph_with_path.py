import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

edges = [
    ("B1", "G2", 3),
    ("G2", "LHC1", 5),
    ("G2", "LHC2", 15),
    ("G2", "Veg Mess", 2),
    ("G2", "NonVeg Mess", 4),
    ("G2", "Sports Complex", 10),
    ("G2", "Main Gate", 20),
    ("G2", "Library", 10),

    ("B1", "LHC1", 3),
    ("B1", "LHC2", 18),
    ("B1", "Veg Mess", 5),
    ("B1", "NonVeg Mess", 2),
    ("B1", "Sports Complex", 15),
    ("B1", "Main Gate", 17),
    ("B1", "Library", 7),

    ("Main Gate", "Library", 13),
    ("Library", "LHC1", 5),
    ("LHC1", "LHC2", 12),
    ("Library", "NonVeg Mess", 10),
    ("Library", "Veg Mess", 13),

    ("Veg Mess", "Sports Complex", 8),
    ("NonVeg Mess", "Sports Complex", 11),
    ("Veg Mess", "Main Gate", 22),
    ("NonVeg Mess", "Main Gate", 19)
]

G.add_weighted_edges_from(edges)

pos = {
    "Veg Mess": (4, 4),
    "NonVeg Mess": (6, 2),

    "LHC2": (-3, 4),
    "G2": (1, 3),
    "Sports Complex": (7, 0),

    "B1": (-5, 2),
    "LHC1": (0, 1),
    "Library": (2, -1),

    "Main Gate": (2, -4)
}

print("\nAvailable Locations:")
for node in G.nodes():
    print(" -", node)

source = input("\nEnter source: ").strip()
dest = input("Enter destination: ").strip()

if source not in G or dest not in G:
    print("\nInvalid location name! Please check spelling.")
    exit()

try:
    path = nx.dijkstra_path(G, source, dest, weight='weight')
    distance = nx.dijkstra_path_length(G, source, dest, weight='weight')
except nx.NetworkXNoPath:
    print("\nNo path found between these locations.")
    exit()

print("\nShortest Distance:", distance, "minutes")
print("Path:", " -> ".join(path))

plt.figure(figsize=(12, 12))

nx.draw_networkx_edges(G, pos, width=2, edge_color="black")

for u, v in zip(path, path[1:]):
    x1, y1 = pos[u]
    x2, y2 = pos[v]
    plt.plot([x1, x2], [y1, y2], color="red", linewidth=5, zorder=50)

nx.draw_networkx_nodes(
    G, pos,
    node_color="#a4d7ff",
    node_size=2500,
    edgecolors="black",
    linewidths=1.3
)

nx.draw_networkx_labels(G, pos, font_size=10, font_weight="bold")

nx.draw_networkx_edge_labels(
    G, pos,
    edge_labels=nx.get_edge_attributes(G, "weight"),
    font_size=9
)

plt.title("IIT Jodhpur Campus Map (Scattered Layout) — Shortest Path Highlighted", fontsize=16)
plt.axis("off")
plt.tight_layout()
plt.show()



