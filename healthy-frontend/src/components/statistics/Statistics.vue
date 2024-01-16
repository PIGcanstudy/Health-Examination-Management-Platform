<template>
    <!-- 统计 -->
    <div style="background-color: white;padding: 15px;margin-top: 10px;">
        <div id="echars" style="height: 200px;"></div>
    </div>
</template>

<script setup>
import { defineProps } from 'vue'

const props = defineProps({
    statistics: {
        type: Array,
        default: () => []
    }
})

import * as echarts from 'echarts'
import { onMounted } from 'vue'

onMounted(() => {
    var myChart = echarts.init(document.getElementById('echars'))

    myChart.setOption({
        tooltip: {
            trigger: 'item',
            formatter: '{a} <br/>{b}: {c} ({d}%)'
        },
        legend: {
            data: [
                '未评价',
                '已评价',
                '未登记',
                '在体检',
                '已总检',
            ],
            orient: 'vertical',
            left: 'left',
            top: 'top'
        },
        series: [
            {
                name: '体检完成率',
                type: 'pie',
                selectedMode: 'single',
                radius: [0, '55%'],
                label: {
                    show: true,
                    position: 'inner',
                    fontSize: 14
                },
                labelLine: {
                    show: false
                },
                data: [
                    { value: 1548, name: '未登记' },
                    { value: 775, name: '在体检' },
                    { value: 679, name: '已总检' }
                ]
            },
            {
                name: '评价完成率',
                type: 'pie',
                radius: ['70%', '90%'],
                labelLine: {
                    length: 30
                },
                label: {
                    show: true
                },
                data: [
                    { value: 1048, name: '未评价' },
                    { value: 335, name: '已评价' },
                ]
            }
        ]
    })
})

</script>

<style lang="scss" scoped>

</style>
