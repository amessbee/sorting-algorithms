import copy
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import random

def counting_sort_plotly_with_speed(arr):
    """
    Build and return a Plotly Figure that animates the Counting Sort process
    with speed controls (Slow, Normal, Fast) plus Pause, arranged so that
    the controls and annotations do not overlap.
    """

    # ────────── STEP 1: RECORD "STATES" OF THE ALGORITHM ──────────
    states = []

    def record_state(description, arr_snapshot, count_snapshot, out_snapshot,
                     highlight_arr=None, highlight_count=None, highlight_out=None):
        """Store a snapshot of the algorithm's state at a given step."""
        states.append({
            "description": description,
            "arr": copy.copy(arr_snapshot),
            "count": copy.copy(count_snapshot),
            "out": copy.copy(out_snapshot),
            "highlight_arr": highlight_arr,
            "highlight_count": highlight_count,
            "highlight_out": highlight_out
        })

    # Handle empty array edge case
    if not arr:
        states.append({
            "description": "Array is empty! Nothing to sort.",
            "arr": [],
            "count": [],
            "out": [],
            "highlight_arr": None,
            "highlight_count": None,
            "highlight_out": None
        })
        return _build_figure(states)

    # Prepare arrays
    original_arr = list(arr)
    max_val = max(arr)
    count_arr = [0] * (max_val + 1)
    out_arr = [0] * len(arr)

    # Record key moments
    record_state("Initial array", original_arr, count_arr, out_arr)
    record_state(f"Maximum value = {max_val}", original_arr, count_arr, out_arr)
    record_state("Initialized count array", original_arr, count_arr, out_arr)

    # 1) Counting frequencies
    for i, val in enumerate(original_arr):
        count_arr[val] += 1
        record_state(
            f"Counting freq... arr[{i}]={val} → count[{val}]={count_arr[val]}",
            original_arr, count_arr, out_arr,
            highlight_arr=i,
            highlight_count=val
        )

    # 2) Building cumulative frequencies
    for i in range(1, len(count_arr)):
        count_arr[i] += count_arr[i - 1]
        record_state(
            f"Cumulative freq... count[{i}]={count_arr[i]}",
            original_arr, count_arr, out_arr,
            highlight_count=i
        )

    # 3) Placing elements (stable sort)
    for i in reversed(range(len(original_arr))):
        val = original_arr[i]
        count_arr[val] -= 1
        pos = count_arr[val]
        out_arr[pos] = val
        record_state(
            f"Placing arr[{i}]={val} → out[{pos}]={val}",
            original_arr, count_arr, out_arr,
            highlight_arr=i,
            highlight_count=val,
            highlight_out=pos
        )

    # Final
    record_state("Done! Sorted array obtained.", original_arr, count_arr, out_arr)

    return _build_figure(states)


def _build_figure(states):
    """
    Given the recorded states from Counting Sort, build a Plotly figure
    with subplots, frames, and interactive controls (including speed),
    arranged to avoid overlapping elements in the layout.
    """

    # Create subplots with extra vertical space
    fig = make_subplots(
        rows=3, cols=1,
        vertical_spacing=0.15,
        subplot_titles=["Original Array", "Count Array", "Output Array"],
    )

    # Initialize from the 0th state
    init_state = states[0]

    # Bar traces for each subplot
    fig.add_trace(
        go.Bar(
            y=init_state["arr"],
            marker_color=_bar_colors(init_state["arr"], init_state["highlight_arr"])
        ),
        row=1, col=1
    )
    fig.add_trace(
        go.Bar(
            y=init_state["count"],
            marker_color=_bar_colors(init_state["count"], init_state["highlight_count"])
        ),
        row=2, col=1
    )
    fig.add_trace(
        go.Bar(
            y=init_state["out"],
            marker_color=_bar_colors(init_state["out"], init_state["highlight_out"])
        ),
        row=3, col=1
    )

    # We use two annotations at the top:
    #  1) A static main title (bigger) 
    #  2) A dynamic step description (just below the main title)
    fig.update_layout(
        margin=dict(t=170, r=40, l=40),  # Extra top margin so controls and titles fit
        annotations=[
            dict(
                x=0.5, y=1.27,
                xref="paper", yref="paper",
                text="Counting Sort Visualization with Speed Control",
                showarrow=False,
                font=dict(size=16),
                xanchor="center"
            ),
            dict(
                x=0.5, y=1.18,
                xref="paper", yref="paper",
                text=init_state["description"],
                showarrow=False,
                font=dict(size=14),
                xanchor="center",
                name="step_description"
            )
        ]
    )

    # Build frames for each recorded state
    frames = []
    for idx, state in enumerate(states):
        frames.append(go.Frame(
            name=str(idx),
            data=[
                go.Bar(
                    y=state["arr"],
                    marker_color=_bar_colors(state["arr"], state["highlight_arr"])
                ),
                go.Bar(
                    y=state["count"],
                    marker_color=_bar_colors(state["count"], state["highlight_count"])
                ),
                go.Bar(
                    y=state["out"],
                    marker_color=_bar_colors(state["out"], state["highlight_out"])
                )
            ],
            layout=go.Layout(
                annotations=[
                    dict(
                        x=0.5, y=1.27,
                        xref="paper", yref="paper",
                        text="Counting Sort Visualization with Speed Control",
                        showarrow=False,
                        font=dict(size=16),
                        xanchor="center"
                    ),
                    dict(
                        x=0.5, y=1.18,
                        xref="paper", yref="paper",
                        text=state["description"],
                        showarrow=False,
                        font=dict(size=14),
                        xanchor="center"
                    )
                ]
            )
        ))
    fig.frames = frames

    # Create a slider to jump through frames
    slider = {
        "active": 0,
        "y": 1.19,
        "x": 0.20,
        "len": 0.60,
        "xanchor": "left",
        "yanchor": "top",
        "steps": [
            {
                "label": str(i),
                "method": "animate",
                "args": [
                    [str(i)],
                    {
                        "frame": {"duration": 0, "redraw": True},
                        "mode": "immediate",
                        "transition": {"duration": 0},
                    },
                ],
            }
            for i in range(len(states))
        ],
    }

    # Speed & Pause buttons
    updatemenus = [
        {
            "type": "buttons",
            "showactive": True,
            # Place these just above the slider, aligned left
            "x": 0.05,
            "y": -0.09,
            "xanchor": "left",
            "yanchor": "bottom",
            "direction": "left",
            "buttons": [
                {
                    "label": "Slow",
                    "method": "animate",
                    "args": [
                        None,
                        {
                            "frame": {"duration": 2000, "redraw": True},
                            "fromcurrent": True,
                            "transition": {"duration": 500, "easing": "linear"},
                        },
                    ],
                },
                {
                    "label": "Normal",
                    "method": "animate",
                    "args": [
                        None,
                        {
                            "frame": {"duration": 1000, "redraw": True},
                            "fromcurrent": True,
                            "transition": {"duration": 500, "easing": "linear"},
                        },
                    ],
                },
                {
                    "label": "Fast",
                    "method": "animate",
                    "args": [
                        None,
                        {
                            "frame": {"duration": 300, "redraw": True},
                            "fromcurrent": True,
                            "transition": {"duration": 300, "easing": "linear"},
                        },
                    ],
                },
                {
                    "label": "Pause",
                    "method": "animate",
                    "args": [
                        [None],
                        {
                            "mode": "immediate",
                            "frame": {"duration": 0, "redraw": False},
                            "transition": {"duration": 0},
                        },
                    ],
                },
            ],
        }
    ]

    fig.update_layout(
        updatemenus=updatemenus,
        sliders=[slider]
    )

    # Keep axes stable by determining max bar heights
    max_arr_val = 0
    max_count_val = 0
    max_out_val = 0
    for st in states:
        if st["arr"]:
            max_arr_val = max(max_arr_val, max(st["arr"]))
        if st["count"]:
            max_count_val = max(max_count_val, max(st["count"]))
        if st["out"]:
            max_out_val = max(max_out_val, max(st["out"]))

    fig.update_yaxes(range=[0, max_arr_val * 1.1], row=1, col=1)
    fig.update_yaxes(range=[0, max_count_val * 1.1], row=2, col=1)
    fig.update_yaxes(range=[0, max_out_val * 1.1], row=3, col=1)

    # Also fix x-axis ranges so bars don't shift
    arr_len = len(states[-1]["arr"])
    count_len = len(states[-1]["count"])
    out_len = len(states[-1]["out"])
    fig.update_xaxes(range=[-0.5, arr_len - 0.5], row=1, col=1)
    fig.update_xaxes(range=[-0.5, count_len - 0.5], row=2, col=1)
    fig.update_xaxes(range=[-0.5, out_len - 0.5], row=3, col=1)

    return fig


def _bar_colors(values, highlight_idx=None):
    """
    Utility: color bars a teal gradient based on value, 
    except the highlighted bar, which is red ('crimson').
    """
    colors = []
    for i, val in enumerate(values):
        if i == highlight_idx:
            colors.append("crimson")
        else:
            teal_base = max(20, 200 - val * 5)
            colors.append(f"rgb(0, {teal_base}, {teal_base})")
    return colors


# Example usage:
if __name__ == "__main__":
    data = [random.randint(1, 50) for _ in range(100)]
    fig = counting_sort_plotly_with_speed(data)
    fig.show()
